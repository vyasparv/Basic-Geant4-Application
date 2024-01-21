#include "DetectorConstruction.hh"

/*
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4NistManager.hh>
#include <G4SystemOfUnits.hh>
#include <G4VisAttributes.hh>
*/
#include <G4Box.hh>
// #include <G4Tubs.hh>
// #include <G4Sphere.hh>
// #include <G4Orb.hh>

DetectorConstruction::DetectorConstruction()
{}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume* DetectorConstruction::Construct() 
{
	G4NistManager *nist = G4NistManager::Instance();

	G4Material* SiO2 = new G4Material("SiO2", 2.202 * g / cm3, 2);
	SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
	SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

	G4Material* H2O = new G4Material("H2O", 1.000 * g / cm3, 2);
	SiO2->AddElement(nist->FindOrBuildElement("H"), 2);
	SiO2->AddElement(nist->FindOrBuildElement("O"), 1);

	G4Element* C = nist->FindOrBuildElement("C");

	G4Material* Aerogel = new GMaterial("Aerogel", 0.200g / cm3, 3); 
	Aerogel->AddMaterial(SiO2, 62.5*perCent);
	Aerogel->AddMaterial(H2O, 37.4*perCent);
	Aerogel->AddElement(C, 0.1*perCent);

	//refractive index 

	G4Double energy[2] = {1.239841939 * eV / 0.9, 1.239841939 * eV / 0.2};
	G4double rindexAerogel[2] = { 1.1, 1.1 };
	G4double rindexWorld[2] = { 1.1, 1.0 };
	
	G4MaterialPropertiesTable* mptAerogel = new G4MaterialPropertiesTable();
	mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2);

	Aerogel->SetMaterialPropertiesTable(mptAerogel);

	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

	G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
	mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);

	worldMat->SetMaterialPropertiesTable(mptWorld);

	G4Box* solidWorld = new G4Box("solidWorld", 0.5 * m, o.5 * m, 0.5 * m);

	G4LogicalVolume* logicalWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

	G4VPhysicalVolume* physWorld = new G4VPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

	G4Box* solidRadiator = new G4Box("solidRadiator", 0.4 * m, 0.4 * m, 0.01 * m);

	G4LogicalVolume* logicalRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicalRadiator");

	G4PhysicalVolune* physRadiator = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.25 * m), logicalRadiator, "physRadiator", logicWorld, false, 0, true);

	G4Box* solidDetector = new G4Box("solidDetector", 0.005 * m, 0.005 * m, 0.01 * m);

	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");

	for(G4int i = 0; i < 100; i++)
	{
		for (G4int j = 0; j < 100; j++)
		{
			G4VPhysicalVolume* physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5 * m + (i + 0.5) * m / 100, -0.5 * m + (j + 0.5) * m / 100, 0.49 * m), logicDetector, "physDetector", logicWorld, false, j + i * 100, true);
		}
	}


	// Return the world volume
	return physWorld;
}

// sensitive detector
void DetectorConstruction::ConstructSDandField()
{
	SensitiveDetector* sensDet = new SensitiveDetector("SensitiveDetector"); 

	logicDetector->SetSensitiveDetector(sensDet);
}
