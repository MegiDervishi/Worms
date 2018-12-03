#ifndef GAME_H
#define GAME_H

#include "QVector"
#include "QMap"

#include "../Physics/RigidBody.h"
#include "../Physics/PhysicsEngine.h"

#include "Projectile.h"
#include "worms.h"

class Game{
    public:
      Game(int nb_worms, double max_turn_time=90000, unsigned int nb_teams=2);

      void update(double dt); //general update: deal with physics

      bool isFinished(); //returns if the game is finished, i.e. if there is only worms of one team left


    private:
      PhysicsEngine physics_engine;
      QVector<int> worms_ids;

      double max_turn_time;

      double turn_timer;

      QVector<int> worms_playing; //index in vector worms of each team
      bool finished; //false

      QVector<Worm*> worms;
      QVector<Projectile*> projectiles;
};
#endif // GAME_H
