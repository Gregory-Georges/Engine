#ifndef STRINGREGEXTANSFORM_HPP_INCLUDED
#define STRINGREGEXTANSFORM_HPP_INCLUDED

#include <string>
#include <regex>
#include <memory>
#include <unordered_set>
#include <fstream>



namespace Engine::StringRegexTransform
{
    std::unique_ptr<std::unordered_set<std::string>> SeparateIntoTokens(std::string& str_to_divide)
    {
        static std::regex regular_expression("[^\\w^_]");
        std::sregex_token_iterator iter(str_to_divide.begin(), str_to_divide.end(), regular_expression, -1);

        std::unique_ptr<std::unordered_set<std::string>> tokens = std::make_unique<std::unordered_set<std::string>>();
        std::sregex_token_iterator end;
        for ( ; iter != end; ++iter)
            if(tokens->find(*iter) == tokens->end())
                tokens->insert(*iter);

        return tokens;
    }



    std::unique_ptr<std::unordered_set<std::string>> SeparateFileIntoTokens(std::string& path_to_divide)
    {
        static std::regex regular_expression("[^\\w^_]");

        std::unique_ptr<std::unordered_set<std::string>> tokens = std::make_unique<std::unordered_set<std::string>>();
        std::fstream file(path_to_divide);
        if(!file.is_open())
        {
            std::cout << file.is_open() << " : Error opening file : " << path_to_divide << "\n";
            return tokens;
        }

        std::string line;
        while(std::getline(file, line))
        {
            std::sregex_token_iterator iter(line.begin(), line.end(), regular_expression, -1);
            std::sregex_token_iterator end;
            for ( ; iter != end; ++iter)
                if(tokens->find(*iter) == tokens->end())
                    tokens->insert(*iter);
        }

        return tokens;
    }
}



#endif // STRINGREGEXTANSFORM_HPP_INCLUDED
