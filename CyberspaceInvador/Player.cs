using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace CyberspaceInvador
{
    public class Player : Sprite
    {
        private Image _playerImage;

        public Player()
        {
            _playerImage = new Image { Source = CreateBitmap(@"Assets/Player.gif") };

            Width = 20;
            Height = 20;
            IsDead = false;
        }

        public bool IsDead { get; set; }
        public void Move(int targetX)
        {
            if (targetX > 0 && targetX < _canvas.Width - Width/2) X = targetX;
        }

        public void ShootLaser(LaserCollection lasers)
        {
            int laserX = X + Width/2;
            int laserY = Y + Height;
            Laser laser = new Laser(laserX, laserY, lasers);
            laser.DisplayOn(_canvas);
        }

        public override void DisplayOn(Canvas drawingCanvas)
        {
            X = Width / 2;
            Y = (int)drawingCanvas.Height - 2 * Height;
            drawingCanvas.Children.Add(_playerImage);
            _canvas = drawingCanvas;
        }

        protected override void UpdateElement()
        {
            _playerImage.Width = Width;
            _playerImage.Height = Height;
            _playerImage.Margin = new System.Windows.Thickness(X, Y, 0, 0);
        }
    }
}
