#include "PrimaryGeneratorAction.hh"

// Select one of the two header files (or keep them both)
#include <G4ParticleGun.hh>
#include <G4GeneralParticleSource.hh>
#include <G4SystemOfUnits.hh>

using namespace std;

fParticleGun = new G4ParticleGun(1);

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	// Select your implementation here:
	delete fParticleGun 
	// 1. GPS (no further commands necessary or recommended)
	//fGenerator = make_shared<G4GeneralParticleSource>();
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	// By default, use the wrapped internal generator
	//fGenerator->GeneratePrimaryVertex(anEvent);

	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName = "proton";
	G4ParticleDefinition* particle = particleTable->FindParticle("proton");

	G4ThreeVector pos(0., 0., 0.); //it will be created in centre of mothervolume
	G4ThreeVector mom(0., 0., 1.);

	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);
	fParticalGun->SetParticleMomentum(100. * GeV);
	fParticleGun->SetParticleDefinition(particle);

	fParticleGun->GeneratePrimaryVertex(anEvent);
}
