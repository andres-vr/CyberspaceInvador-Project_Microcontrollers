using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows;

namespace CyberspaceInvador
{
    public class Laser : Sprite
    {
        private Ellipse _ellipse;
        private int _stepSize;
        private LaserCollection _laserCollection;

        public Laser(int x, int y, LaserCollection laserCollection)
        {
            _ellipse = new Ellipse { Fill = new SolidColorBrush(Colors.Black) };
            _stepSize = 5;
            _laserCollection = laserCollection;

            X = x;
            Y = y;
            Width = 5;
            Height = 10;

            _laserCollection.Add(this);
        }

        public override void DisplayOn(Canvas drawingCanvas)
        {
            drawingCanvas.Children.Add(_ellipse);
            _canvas = drawingCanvas;
        }

        public void Move()
        {
            if (Y < 0)
            {
                _laserCollection.Remove(this);
                _canvas.Children.Remove(_ellipse);
            }
            else
            {
                Y -= _stepSize;
            }
        }

        public void CheckHit(Alien alien)
        {
            if (HasHit(alien))
            {
                alien.IsDead = true;
            }
        }

        public void CheckHit(Wall wall)
        {
            if (HasHit(wall))
            {
                _laserCollection.Remove(this);
                _canvas.Children.Remove(_ellipse);
            }
        }
        protected override void UpdateElement()
        {
            _ellipse.Margin = new Thickness(X, Y, 0, 0);
            _ellipse.Width = Width;
            _ellipse.Height = Height;
        }
    }
}
