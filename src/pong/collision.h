#ifndef COLLISION_H
#define COLLISION_H

#include "types.h"

struct Collision {
	char *entity_name;
	void *entity;
};

Collision *Collision_init(char *entity_name, void *entity);

#endif
