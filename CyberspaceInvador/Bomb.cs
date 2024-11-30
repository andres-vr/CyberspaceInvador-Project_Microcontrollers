using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows;
using System.Windows.Shapes;

namespace CyberspaceInvador
{
    public class Bomb : Sprite
    {
        private Ellipse _ellipse;
        private int _stepSize;
        private BombCollection _bombCollection;
        public Bomb(int x, int y, BombCollection bombCollection)
        {
            _ellipse = new Ellipse { Fill = new SolidColorBrush(Colors.Black) };
            _stepSize = 5;
            _bombCollection = bombCollection;
            X = x;
            Y = y;
            Width = 5;
            Height = 5;
            _bombCollection.Add(this);
        }
        public override void DisplayOn(Canvas drawingCanvas)
        {
            drawingCanvas.Children.Add(_ellipse);
            _canvas = drawingCanvas;
        }
        public void Move()
        {
            if (Y > _canvas.Height)
            {
                _bombCollection.Remove(this);
                _canvas.Children.Remove(_ellipse);
            }
            else
            {
                Y += _stepSize;
            }
        }

        public void CheckHit(Player player)
        { 
            if (HasHit(player)) 
            {
                player.IsDead = true;
            }
        }

        public void CheckHit(Wall wall)
        {
            if (HasHit(wall))
            {
                _bombCollection.Remove(this);
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
