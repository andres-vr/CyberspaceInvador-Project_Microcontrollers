﻿    using System;
    using System.IO.Ports;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows;
    using System.Windows.Controls;
    using System.Windows.Data;
    using System.Windows.Documents;
    using System.Windows.Input;
    using System.Windows.Media;
    using System.Windows.Media.Imaging;
    using System.Windows.Navigation;
    using System.Windows.Shapes;
    using System.Windows.Threading;
    using System.Windows.Media.Converters;
using System.Threading;
using System.Numerics;

namespace CyberspaceInvador
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private Player _player = new Player();
        private Alien _alien = new Alien();

        private LaserCollection _lasers;
        private BombCollection _bombs;

        private DispatcherTimer _animationTimer = new DispatcherTimer();
        private DispatcherTimer _bombTimer;

        private Wall _wall = new Wall();

        private SerialPort serialPort;

        int targetX;


        public MainWindow()
        {
            InitializeComponent();
            connectPort();
            _player.DisplayOn(gameCanvas);
            _alien.DisplayOn(gameCanvas);
            _wall.DisplayOn(gameCanvas);

            _lasers = new LaserCollection();
            _bombs = new BombCollection();

            _animationTimer.Interval = TimeSpan.FromMilliseconds(5);
            _animationTimer.Tick += _animationTimer_Tick;
            _animationTimer.Start();

            _bombTimer = new DispatcherTimer
            {
                Interval = TimeSpan.FromMilliseconds(250)
            };
            _bombTimer.Tick += _bombTimer_Tick;
            _bombTimer.Start();

            targetX =Convert.ToInt32( gameCanvas.Width / 2);
            _player.Move(targetX);
        }

        private void _bombTimer_Tick(object? sender, EventArgs e)
        {
            _alien.DropBomb(_bombs);
        }

        private void _animationTimer_Tick(object? sender, EventArgs e)
        {
            _alien.Move();
            _lasers.Move();
            _bombs.Move();

            _bombs.CheckHit(_player);
            _lasers.CheckHit(_alien);

            if (_alien.IsDead) 
            {
                SendData("Xp\n");
                Thread.Sleep(5000);
                EndGame("player");
            }
            else if (_player.IsDead) 
            {
                SendData("Xa\n");
                Thread.Sleep(5000);
                EndGame("alien");
            }
        }



        private void EndGame(string winner)
        { 
            _animationTimer.Stop();
            _bombTimer.Stop();
            //MessageBox.Show($"game over - {winner} wins");
            Environment.Exit(0);
            
        }

        private void connectPort()
        {
            // Setup serial port
            serialPort = new SerialPort("COM8", 115200, Parity.None, 8, StopBits.One);
            serialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            try
            {
                serialPort.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Failed to connect: {ex.Message}");
                Environment.Exit(0);
            }
        }

        public void SendData(string data)
        {
                try
                {
                serialPort.WriteLine(data);
                serialPort.BaseStream.Flush();
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error sending data: {ex.Message}");
                }
        }

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                
                string data = serialPort.ReadExisting(); 
                Dispatcher.Invoke(() =>
                {
                    if (string.IsNullOrEmpty(data))
                    {

                    }
                    else if (data == "0\n" || data == "0") // Move left
                    {
                        targetX = targetX - 15;
                        _player.Move(targetX);
                    }
                    else if (data == "1\n" || data == "1") // Move right
                    {
                        targetX = targetX + 15;
                        _player.Move(targetX);
                    }
                    else if (data == "2\n" || data == "2") // Shoot
                    {
                        _player.ShootLaser(_lasers);
                    }
                    else
                    {
                        //MessageBox.Show(data);
                    }
                });
            }
            catch (Exception ex)
            {
                Dispatcher.Invoke(() => {
                    MessageBox.Show($"Error receiving data: {ex.Message}");
                });
            }
        }
    }
}
