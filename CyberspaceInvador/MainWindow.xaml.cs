    using System;
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

namespace CyberspaceInvador
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private int left = 5;

        private Player _player = new Player();
        private Alien _alien = new Alien();

        private LaserCollection _lasers;
        private BombCollection _bombs;

        private DispatcherTimer _animationTimer = new DispatcherTimer();
        private DispatcherTimer _bombTimer;

        private Wall _wall = new Wall();

        private SerialPort serialPort;

        public MainWindow()
        {
            InitializeComponent();
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

            if (_alien.IsDead) { EndGame("player"); }
            else if (_player.IsDead) { EndGame("alien"); }
        }
        private void gameCanvas_MouseMove(object sender, MouseEventArgs e)
        {
            var targetX = (int)(e.GetPosition(gameCanvas).X - _player.Width / 2);
            //                                 tov van   player in midden van de muis
            _player.Move(targetX);
        }
        private void gameCanvas_MouseUp(object sender, MouseButtonEventArgs e)
        {
            _player.ShootLaser(_lasers);
        }

        private void EndGame(string winner)
        { 
            _animationTimer.Stop();
            _bombTimer.Stop();
            MessageBox.Show($"game over - {winner} wins");
            Environment.Exit(0);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string hoi = "hoi";
            MessageBox.Show(hoi);
            // Setup serial port
            serialPort = new SerialPort("COM5", 57600, Parity.None, 8, StopBits.One);
            serialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            try
            {
                serialPort.Open();
                MessageBox.Show("Connected to PSoC on COM5");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Failed to connect: {ex.Message}");
            }
        }

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                string data = serialPort.ReadExisting();  // Read data from serial port
                if (data != "0")
                {
                    MessageBox.Show(data);
                    if (data == "1")
                    {
                        MessageBox.Show("123");
                        int xValue = 765 / 2;
                        xValue += left;
                        //_player.Move(xValue);
                    }
                }

                // Update the UI in a thread-safe way
                /* Dispatcher.Invoke(() => {
                     ReceivedDataTextBox.AppendText(data + Environment.NewLine);  // Append data to the text box
                     ReceivedDataTextBox.ScrollToEnd();  // Auto-scroll to the latest message
                 });*/
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
