#include "homework1.h"

namespace gazebo
{

void Homework1::Load(int /*_argc*/, char ** /*_argv*/)
{
}

void Homework1::OnUpdate(const common::UpdateInfo & /*_info*/)
{
    physics::ModelPtr m_box = world_->GetModel("box1");
    physics::ModelPtr m_sphere = world_->GetModel("sphere1");

    m_box->SetLinearVel(math::Vector3(.03, 0, 0));
    m_sphere->SetLinearVel(math::Vector3(.03, 0, 0));
}

void Homework1::Init()
{
    // get the World
    world_ = physics::get_world();
    // get world name and print
    world_name_ = world_->GetName();
    std::cout << "World Name: " << world_name_ << "\n";

    // get and print physic engine
    phy_eng_ = world_->GetPhysicsEngine();
    phy_eng_name_ = phy_eng_->GetType();
    std::cout << "Physic Engine: " << phy_eng_name_ << "\n";

    // get the model count
    model_count_ = world_->GetModelCount();
    std::cout << "Model Count: " << model_count_ << "\n";

    this->updateConnection_ = event::Events::ConnectWorldUpdateBegin(boost::bind(&Homework1::OnUpdate, this, _1));
}

}