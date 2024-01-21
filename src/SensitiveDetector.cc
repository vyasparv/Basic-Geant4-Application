#include "SensitiveDetector.hh"

SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

SensitiveDetector::~SensitiveDetector()
{}

G4bool SensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *R0hist)
{
	G4Track* track = astep->GetTrack();

	track->SetTrackStatus(fStopAndKill);

	G4StepPoints* preStepPoint = aStep->GetPreStepPoint(); 
	G4StepPoints* postStepPoint = aStep->GetPostStepPoint();

	G4ThreeVector posPhoton = preStepPoint->GetPosition(); 

	//G4cout << "The position of Photon is: " << posPhoton << Gendl; 

	const G4VTouchable* touchable = aStep->GetPreStepPoint()->GetTouchable();

	G4int copyNo = touchable->GetCopyNumber();

	//G4cout << "Copy number:" << copyNo << G4endl;

	G4PhysicalVolume* physVol = touchable->GetVolume();
	G4ThreeVector posDetector = physVol->GetTranslation();

	G4Cout << "Detector position:" << posDetector << G4endl;

	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID(); 

	G4AnalysisManager* man = G4AnalysisManager::Instance(); 
	man->FillNtupleIColumn(0, evt); 
	man->FillNtupleDColumn(1, posDetector[0]); 
	man->FillNtupleDColumn(2, posDetector[1]);
	man->FillNtupleDColumn(3, posDetector[2]);
	man->AddNtupleRow(0);
} 