#include "PhysicsList.hh"

// physics constructors in Geant4
#include <G4OpticalPhysics.hh>
#include <G4EmStandardPhysics_option4.hh>

#include <G4StepLimiterPhysics.hh>

PhysicsList::PhysicsList()
{
	// a) add physics constructors
	RegisterPhysics(new G4OpticalPhysics());
	RegisterPhysics(new G4EmStandardPhysics());
	RegisterPhysics(new G4StepLimiterPhysics());

	// b) set a reference physics list and use it
	// = create a pointer and reuse it in other methods
}

PhysicsList::~PhysicsList()

/*
void PhysicsList::ConstructParticle()
{
	// Call parent method (using the constructors)
	G4VModularPhysicsList::ConstructParticle();
	
	// OR use the physics list
	// OR define some particles yourself
}

void PhysicsList::ConstructProcess()
{
	// Call parent method (using the constructors)
	G4VModularPhysicsList::ConstructProcess();

	// OR use the physics list
	// OR define some processes yourself
}

void PhysicsList::SetCuts()
{
	// Call parent method (using the constructors)
	G4VModularPhysicsList::SetCuts();
	
	// Add your specifics
}
*/