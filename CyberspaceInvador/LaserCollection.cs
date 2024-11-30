using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CyberspaceInvador
{
    public class LaserCollection
    {
        private List<Laser> _laserList = new List<Laser>();

        public void Add(Laser laser) { _laserList.Add(laser);}
        public void Remove(Laser laser) { _laserList.Remove(laser);}
        
        public void Move() 
        {
            /*foreach (Laser laser in _laserList) //bij foreach mag je collectie niet meer veranderen, dus niet meer moven
                {
                    laser.Move();
                }
            */
            for (int i = 0; i < _laserList.Count; i++)
            {
                _laserList[i].Move();
            }
        }

        public void CheckHit(Alien alien)
        {
            for (var i = 0; i < _laserList.Count; i++)
            {
                _laserList[i].CheckHit(alien);
            }
        }
    }
}
