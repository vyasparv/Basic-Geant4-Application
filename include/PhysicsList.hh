#ifndef PHYSICS_LIST_HH
#define PHYSICS_LIST_HH

#include <G4VModularPhysicsList.hh>
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"

class PhysicsList : public G4VModularPhysicsList
{
	PhysicsList();
	~PhysicsList();
};

#endif