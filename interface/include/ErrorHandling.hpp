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
        class LibraryLoadException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Failed to load library");
                }
        };
        class NoEntryPointException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Entry point not found");
                }
        };
        class InvalidLibraryException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Invalid library");
                }
        };
        class FailedToInitializeException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Failed to initialize");
                }
        };
        class WindowCreationFailedException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Window could not be created");
                }
        };
        class RendererCreationFailedException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Renderer could not be created");
                }
        };
        class WindowSurfaceFailureException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Could not get window surface");
                }
        };
        class FailedToLoadImageException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Failed to load image");
                }
        };
        class FailedToCreateTextureException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Failed to create texture");
                }
        };
        class FailedToCreateTextSurfaceException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Failed to create text surface");
                }
        };
        class FailedToCreateTextTextureException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Failed to create text texture");
                }
        };
        class FailedToLoadFontException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Failed to load font");
                }
        };
        class FailedToLoadTextureException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return ("Failed to load texture");
                }
        };
    };

#endif /* !ERRORHANDLING_HPP_ */
