#include <stdlib.h>

#include "collision.h"

Collision *Collision_init(char *entity_name, void *entity) {
	Collision *collision = malloc(sizeof(Collision));
	collision->entity_name = entity_name;
	collision->entity = entity;

	return collision;
}
