using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media.Imaging;

namespace CyberspaceInvador
{
    public abstract/*geen objecten van maken*/ class Sprite
    {
		private int _x; private int _y; private int _width; private int _height;
		//protected Canvas?_canvas;  maakt het nullable
		protected Canvas _canvas = null!; //null forgiving operator: we moeten er straks geen null in plaatsen

        public int X
		{
			get { return _x; }
			set { _x = value; UpdateElement(); }
		}

		public int Y
		{
			get { return _y; }
			set { _y = value; UpdateElement(); }
		}

		public int Width
		{
			get { return _width; }
			set { _width = value; UpdateElement(); }
		}

		public int Height
		{
			get { return _height; }
			set { _height = value; UpdateElement(); }
		}

		public abstract void DisplayOn(Canvas drawingCanvas); //moet door kind klasse gedefinieerd worden
		protected abstract void UpdateElement();

		protected BitmapImage CreateBitmap(string imagepath) //hoofdstuk 3 code
		{
			BitmapImage bitmapImage = new BitmapImage();
			bitmapImage.BeginInit();
			bitmapImage.UriSource = new Uri(imagepath, UriKind.RelativeOrAbsolute);
			bitmapImage.EndInit();
			return bitmapImage;
		}

        protected bool HasHit(Sprite otherSprite)
        {
            if (IsOnTheLeftOf(otherSprite)) return false;
            if (IsOnTheRightOf(otherSprite)) return false;
            if (IsAbove(otherSprite)) return false;
            if (IsBelow(otherSprite)) return false;

            return true;
        }

        private bool IsBelow(Sprite otherSprite)
        {
            return Y > otherSprite.Y + otherSprite.Height;
        }

        private bool IsAbove(Sprite otherSprite)
        {
            return Y + Height < otherSprite.Y;
        }

        private bool IsOnTheRightOf(Sprite otherSprite)
        {
            return X > otherSprite.X + otherSprite.Width;
        }

        private bool IsOnTheLeftOf(Sprite otherSprite)
        {
            return X + Width < otherSprite.X;
        }
    }
}