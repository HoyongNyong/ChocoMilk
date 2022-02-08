#include"ChocoMilk/core/Component/Entity.h"
#include"ChocoMilk/core/Component/ComponentMaster.h"
#include"ChocoMilk/core/Component/BasicComponents.h"

namespace ChocoMilk {
	class Player : public scriptableEntity {
		Player(ComponentMaster* cmp) {
			cmp->AddComponent<positionComponent>(id);
			script(cmp);
		}
	private:
		void script(ComponentMaster* cmp) {
			CREATE
				cmp->GetComponent<positionComponent>(id).x = 20;
			END

			STEP
				cmp->GetComponent<positionComponent>(id).x = 10;
			END

			DRAW
				
			END
		}
	private:

	
	};
	
}