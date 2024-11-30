using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace CyberspaceInvador
{
    public class Wall : Sprite
    {
        private Rectangle _rectangle;
        public Wall()
        {
            _rectangle = new Rectangle() { Fill = new SolidColorBrush(Colors.Black) };
            _rectangle.Height = 2;
            _rectangle.Width = 15;
            _rectangle.Margin = new Thickness(375, 50, 0, 0);
        }

        public override void DisplayOn(Canvas drawingCanvas)
        {
            drawingCanvas.Children.Add(_rectangle);
            _canvas = drawingCanvas;
        }

        public void KillBomb()
        {

        }
        public void CheckHit(Bomb bomb, Laser laser)
        {
            if (HasHit(bomb))
            {
                
            }
            if (HasHit(laser))
            {

            }
        }

        protected override void UpdateElement()
        {
            
        }
    }
}
