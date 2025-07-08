#include "ShrubberyCreationForm.hpp"

/* ─── OCF ──────────────────────────────────────────────────────────── */
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
    : AForm(o), _target(o._target) {}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);           // copy signed state
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* ─── action ──────────────────────────────────────────────────────── */
void ShrubberyCreationForm::executeAction() const
{
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs) return;

    ofs << "       _-_"            << std::endl
        << "    /~~   ~~\\"        << std::endl
        << " /~~         ~~\\"     << std::endl
        << "{               }"     << std::endl
        << " \\  _-     -_  /"     << std::endl
        << "   ~  \\\\ //  ~"      << std::endl
        << "_- -   | | _- _"      << std::endl
        << "  _ -  | |   -_"      << std::endl
        << "      // \\\\"         << std::endl;
}
