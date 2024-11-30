using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media.Media3D;
using System.Windows;

namespace CyberspaceInvador
{
    public class Alien : Sprite
    {
        private Image _alienImage;
        private int _stepSize;

        public Alien()
        {
            _alienImage = new Image { Source = CreateBitmap(@"Assets\Alien.gif") };
            _stepSize = 3;

            Width = 25;
            Height = 25;
            IsDead = false;
        }

        public bool IsDead { get; set; }

        public override void DisplayOn(Canvas drawingCanvas)
        {
            X = Width / 2;
            Y = Height / 2;
            drawingCanvas.Children.Add(_alienImage);
            _canvas = drawingCanvas;
        }

        public void Move()
        {
            //als hij tegen de rand komt wisselt hij van kant
            if ((X > _canvas.Width - Width) || (X < 0))
            {
                _stepSize = -_stepSize;
            }
            X += _stepSize;
        }

        public void DropBomb(BombCollection bombs)
        {
            var bombX = X + (Width / 2);
            var bombY = Y + Height;
            Bomb bomb = new Bomb(bombX, bombY, bombs);
            bomb.DisplayOn(_canvas);
        }

        public void CheckHit(Alien alien)
        {
            if (HasHit(alien))
            {
                alien.IsDead = true;
            }
        }

        protected override void UpdateElement()
        {
            _alienImage.Margin = new Thickness(X, Y, 0, 0);
            _alienImage.Width = Width;
            _alienImage.Height = Height;
        }
    }


}


