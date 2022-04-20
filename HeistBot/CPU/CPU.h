#pragma once
#include <array>
#include <list>
#include ".\..\C##\Vector2.h"
#include "Behavior.h"
#include ".\..\Movement\MovementEngine.h"
#include ".\..\Mapping\MappingEngine.h"

using namespace std;
using namespace CSS;

namespace HeistBot
{
	namespace CentralProcessing
	{
		class CPU
		{
			public:
				Vector2 position;
                Vector2 enemyPosition;
                Mapping::MappingEngine _Mapping;
                Movement::MovementEngine _Movement;
                //Vision::VisionEngine _Vision;
                //Communication::CommunicationEngine _Comms;

                int activeState = 0;    //  0 is Idle, 1 is Patrol, 2 is Guard, 3 is Attack

                void Initialize ();
                void Update ();

                void SaveRoundData ();
                void LoadBehavior ();

            private:
                bool DataMode = false;
                list<Behavior> EnemyBehaviors;

                Vector2 nextPosition;
                Vector2 enemyNextPosition;
                
                void updatePosition ();
                void updateEnemyPosition ();

                void setActiveState ();

                void Idle ();
                void Patrol ();
                void Guard ();
                void Attack ();
		};
	}
}



