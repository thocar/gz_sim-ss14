#include "homework2.h"

namespace gazebo
{

//////////////////////////////////////////////////
void Homework2::Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
{
  // ──────█▀▄─▄▀▄─▀█▀─█─█─▀─█▀▄─▄▀▀▀─────
  // ──────█─█─█─█──█──█▀█─█─█─█─█─▀█─────
  // ──────▀─▀──▀───▀──▀─▀─▀─▀─▀──▀▀──────
  // ─────────────────────────────────────
  // ───────────────▀█▀─▄▀▄───────────────
  // ────────────────█──█─█───────────────
  // ────────────────▀───▀────────────────
  // ─────────────────────────────────────
  // ─────█▀▀▄─█▀▀█───█──█─█▀▀─█▀▀█─█▀▀───
  // ─────█──█─█──█───█▀▀█─█▀▀─█▄▄▀─█▀▀───
  // ─────▀▀▀──▀▀▀▀───▀──▀─▀▀▀─▀─▀▀─▀▀▀───
  // ─────────────────────────────────────
  // ─────────▄███████████▄▄──────────────
  // ──────▄██▀──────────▀▀██▄────────────
  // ────▄█▀────────────────▀██───────────
  // ──▄█▀────────────────────▀█▄─────────
  // ─█▀──██──────────────██───▀██────────
  // █▀──────────────────────────██───────
  // █──███████████████████───────█───────
  // █────────────────────────────█───────
  // █────────────────────────────█───────
  // █────────────────────────────█───────
  // █────────────────────────────█───────
  // █────────────────────────────█───────
  // █▄───────────────────────────█───────
  // ▀█▄─────────────────────────██───────
  // ─▀█▄───────────────────────██────────
  // ──▀█▄────────────────────▄█▀─────────
  // ───▀█▄──────────────────██───────────
  // ─────▀█▄──────────────▄█▀────────────
  // ───────▀█▄▄▄──────▄▄▄███████▄▄───────
  // ────────███████████████───▀██████▄───
  // ─────▄███▀▀────────▀███▄──────█─███──
  // ───▄███▄─────▄▄▄▄────███────▄▄████▀──
  // ─▄███▓▓█─────█▓▓█───████████████▀────
  // ─▀▀██▀▀▀▀▀▀▀▀▀▀███████████────█──────
  // ────█─▄▄▄▄▄▄▄▄█▀█▓▓─────██────█──────
  // ────█─█───────█─█─▓▓────██────█──────
  // ────█▄█───────█▄█──▓▓▓▓▓███▄▄▄█──────
  // ────────────────────────██──────────
  // ────────────────────────██───▄███▄───
  // ────────────────────────██─▄██▓▓▓██──
  // ───────────────▄██████████─█▓▓▓█▓▓██▄
  // ─────────────▄██▀───▀▀███──█▓▓▓██▓▓▓█
  // ─▄███████▄──███───▄▄████───██▓▓████▓█
  // ▄██▀──▀▀█████████████▀▀─────██▓▓▓▓███
  // ██▀─────────██──────────────██▓██▓███
  // ██──────────███──────────────█████─██
  // ██───────────███──────────────█─██──█
  // ██────────────██─────────────────█───
  // ██─────────────██────────────────────
  // ██─────────────███───────────────────
  // ██──────────────███▄▄────────────────
  // ███──────────────▀▀███───────────────
  // ─███─────────────────────────────────
  // ──███────────────────────────────────
}

//////////////////////////////////////////////////
void Homework2::OnUpdate(const common::UpdateInfo & /*_info*/)
{
    if(common::Time::GetWallTime() - this->_st_time >= 5){

      // get models
      physics::ModelPtr m_sphere_move = this->_world->GetModel("sphere1");
      physics::ModelPtr m_sphere_static = this->_world->GetModel("sphere1_0");
      
      if(!this->_set_link){
        this->_joint_ptr = this->_phy_eng->CreateJoint("revolute", m_sphere_move);
        this->_joint_ptr->Attach(m_sphere_move->GetLink(), m_sphere_static->GetLink());
        this->_joint_ptr->Init();
        this->_set_link = true;
      } 

      if(common::Time::GetWallTime() - this->_st_time >= 15 && !this->_removed_link){
        this->_joint_ptr->Detach();
        this->_removed_link = true;
      } 

      // they see them rollin!
      m_sphere_move->SetLinearVel(math::Vector3(0.5, 0, 0));
  }
}

//////////////////////////////////////////////////
void Homework2::Init()
{ 
    // get the World
    this->_world = physics::get_world();
    this->_st_time = common::Time::GetWallTime();
    this->_set_link = false;
    this->_removed_link = false;

    // get physic engine
    this->_phy_eng = this->_world->GetPhysicsEngine();

    this->_updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&Homework2::OnUpdate, this, _1));
}

}