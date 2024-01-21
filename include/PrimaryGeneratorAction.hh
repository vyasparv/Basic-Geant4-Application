#ifndef PRIMARY_GENERATOR_ACTION_HH
#define PRIMARY_GENERATOR_ACTION_HH

#include <memory>
#include <G4VUserPrimaryGeneratorAction.hh>

class G4VPrimaryGenerator;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
	PrimaryGeneratorAction();
	~PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event*);

private:
	G4ParticleGun *fParticleGun;

};

#endif