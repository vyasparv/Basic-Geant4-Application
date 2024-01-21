#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"

ActionInitialization::ActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::Build() const
{
    // Add your actions
    PrimaryGeneratorAction* generator = new PrimaryGeneratorAction();
    SetUserAction(generator);

    RunAction* runAction = new RunAction(); 
    SetUserAction(runAction); 
}
