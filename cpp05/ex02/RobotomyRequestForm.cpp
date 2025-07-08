#include "RobotomyRequestForm.hpp"


/* ─── OCF ──────────────────────────────────────────────────────────── */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("undefined") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
    : AForm("RobotomyRequestForm", 72, 45), _target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
    : AForm(o), _target(o._target) {}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* ─── action ──────────────────────────────────────────────────────── */
void RobotomyRequestForm::executeAction() const
{
    static bool seeded = false;
    if (!seeded) { std::srand(std::time(0)); seeded = true; }

    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy of " << _target << " failed" << std::endl;
}
