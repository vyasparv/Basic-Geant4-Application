#include "run.hh"

RunAction::RunAction()
{}

RunAction::~RunAction()
{}

void RunAction::BeginOfRunAction(const G4Run*);
{
	G4AnalysisManager* man = G4AnalysisManager::Instance();

	man->OpenFile("data.root"); 

	man->CreateNtuple("Hits", "Hits"); 
	man->CreateNtupleIColumn("fEvent");
	man->CreateNtupleDColumn("fX");
	man->CreateNtupleDColumn("fY");
	man->CreateNtupleDColumn("fZ");
	man->FinishNtuple(0);
}

void RunAction::EndOfRunAction(const G4Run*);
{
	G4AnalysisManager* man = G4AnalysisManager::Instance(); 

	man->Write();
	man->CloseFile();
}