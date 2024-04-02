/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Error handling
*/

#ifndef ERRORHANDLING_HPP_
    #define ERRORHANDLING_HPP_

    #include <exception>

    namespace arcade {
        int checkFunc(char const *const *argv);

        class NoPathException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("No path provided");
                }
        };
        class NoLibraryException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Library not found");
                }
        };
        class NoEntryPointException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Entry point not found");
                }
        };
    };

#endif /* !ERRORHANDLING_HPP_ */
