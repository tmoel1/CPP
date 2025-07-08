#include "PresidentialPardonForm.hpp"

/* ─── OCF ──────────────────────────────────────────────────────────── */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("undefined") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& t)
    : AForm("PresidentialPardonForm", 25, 5), _target(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
    : AForm(o), _target(o._target) {}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* ─── action ──────────────────────────────────────────────────────── */
void PresidentialPardonForm::executeAction() const
{
    std::cout << _target
              << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
