#include <string> 
#include <iostream>

#pragma once

class Warlock {
    public:
        Warlock(std::string const &, std::string const &);
        ~Warlock();

        std::string const & getName(void) const;
        std::string const & getTitle(void) const;

        void    setTitle(std::string const &);

        void    introduce(void) const;

    private:
        Warlock();
        Warlock(Warlock const &);
        Warlock & operator=(Warlock const &);

        std::string name;
        std::string title;
};
