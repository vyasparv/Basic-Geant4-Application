#ifndef SENSITIVE_DETECTOR_HH
#define SENSITIVE_DETECTOR_HH

#include "G4SensitiveDetector.hh"
#include "g4root.hh"
#include "G4RunManager.hh"

class SensitiveDetector : public G4SensitiveDetector
{
public:
	SensitiveDetector(G4String);
	~SensitiveDetector();

private: 
	virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*);
};


#endif 
