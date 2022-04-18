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
	namespace CPU
	{
		class CPU
		{
			public:
				Vector2 position;
                Vector2 enemyPosition;
                Mapping::MappingEngine _Mapping;
                Movement::MovementEngine _Movement;

                void Initialize();
                void Update();

            private:
                list<Behavior> EnemyBehaviors;
                Vector2 nextPosition;
                Vector2 enemyNextPosition;
                
                void updateEnemyPosition ();
		};
	}
}



