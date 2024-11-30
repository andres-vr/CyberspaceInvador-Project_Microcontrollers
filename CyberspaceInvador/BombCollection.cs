using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CyberspaceInvador
{
    public class BombCollection
    {
        private List<Bomb> _bombs = new List<Bomb>();

        public void Add(Bomb bomb)
        { 
            _bombs.Add(bomb);
        }
        public void Remove(Bomb bomb)
        { 
            _bombs.Remove(bomb);
        }

        public void Move()
        {
            for (int i = 0; i < _bombs.Count; i++)
            {
                _bombs[i].Move();
            }
        }

        public void CheckHit(Player player)
        {
            for (var i = 0; i < _bombs.Count; i++)
            {
                _bombs[i].CheckHit(player);
            }
        }


    }
}
