#ifndef DETECTOR_CONSTRUCTION_HH
#define DETECTOR_CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4PhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4VPlacement.hh"
#include "G4NistManager.hh"

#include "SensitiveDetector.hh"


class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction();
    ~DetectorConstruction();

    virtual G4PhysicalVolume* Construct();

private: 
    G4LogicalVolume* logicDetector;
    virtual void ConstructSDandField();
};

#endif