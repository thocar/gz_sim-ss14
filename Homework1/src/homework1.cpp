#include "homework1.h"

namespace gazebo
{

//////////////////////////////////////////////////
void Homework1::Load(int /*_argc*/, char ** /*_argv*/)
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
void Homework1::OnUpdate(const common::UpdateInfo & /*_info*/)
{
    // get models
    physics::ModelPtr m_box = this->_world->GetModel("box1");
    physics::ModelPtr m_sphere = this->_world->GetModel("sphere1");

    // they see them rollin!
    m_box->SetLinearVel(math::Vector3(.03, 0, 0));
    m_sphere->SetLinearVel(math::Vector3(.03, 0, 0));
}

//////////////////////////////////////////////////
void Homework1::Init()
{
    // get the World
    this->_world = physics::get_world();
    // get world name and print
    this->_world_name = this->_world->GetName();
    std::cout << "World Name: " << this->_world_name << "\n";

    // get and print physic engine
    this->_phy_eng = this->_world->GetPhysicsEngine();
    this->_phy_eng_name = this->_phy_eng->GetType();
    std::cout << "Physic Engine: " << this->_phy_eng_name << "\n";

    // get the model count
    this->_model_count = this->_world->GetModelCount();
    std::cout << "Model Count: " << this->_model_count << "\n";

    this->_updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&Homework1::OnUpdate, this, _1));
}

}