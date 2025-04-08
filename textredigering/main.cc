#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>

std::vector<std::string> read_file(std::string const& filename)
{
    std::ifstream file{filename};
    std::vector<std::string> text{};

    copy(std::istream_iterator<std::string>{ file },
         std::istream_iterator<std::string>{ },
         std::back_inserter(text));

    file.close();

    return text;
}

std::vector<std::string> get_args(int argc, char* argv[])
{
    std::vector<std::string> arguments{};
    for (size_t i{}; i < argc; ++i)
    {
        if (!(i == 0 || i == 1))
        {
            arguments.push_back(argv[i]);
        }
    }
    return arguments;
}

void print(std::vector<std::string> const& text)
{
    std::copy(text.begin(), text.end(),
              std::ostream_iterator<std::string>{ std::cout, " "});
    std::cout << std::endl;
}

std::vector<std::string> get_flags(std::vector<std::string> const& args)
{
    std::string flag{};
    std::vector<std::string> flags{};
    
    for (std::string const& arg : args)
    {
        auto it = std::find(arg.begin(), arg.end(), '=');
        std::copy(arg.begin(), it, std::back_inserter(flag));
        flags.push_back(flag);
        ++it;
        flag = "";
    }

    return flags;
}

std::vector<std::string> get_parameters(std::vector<std::string> const& args)
{
    std::string parameter{};
    std::vector<std::string> parameters{};
    
    for (std::string const& arg : args)
    {
        auto it = std::find(arg.begin(), arg.end(), '=');
        ++it;
        std::copy(it, arg.end(), std::back_inserter(parameter));
        parameters.push_back(parameter);
        parameter = "";
    }

    return parameters;
}

void remove(std::string const& word, std::vector<std::string> & text)
{
    auto it = std::remove(text.begin(), text.end(), word);
    text.erase(it, text.end());
}

void replace(std::string const& words, std::vector<std::string> & text)
{
    // Får in parameter typ: hej+då byt ut hej mot då boom ANVÄND std::replace
}

// std::map<std::string, int> get_frequency(std::vector<std::string> const& text)
// {
//     std::map<std::string, int> tmp{};
//     std::vector<std::string> unique{};
//     std::copy(std::unique(text), text.end());
//     // Gör copy till ny vector med all unika ord
//     // Räkna antal av varje ord till en int vector
//     // Sortera unique vectorn med hjälp av int vectorn

// }

void print_frequency(std::map<std::string, int>)
{

}

using namespace std;

int main(int argc, char* argv[])
{
    vector<string> text      { read_file(argv[1]) };
    vector<string> arguments { get_args(argc, argv) };
    vector<string> flags     { get_flags(arguments) };
    vector<string> parameters{ get_parameters(arguments) };

    for (size_t i{}; i < flags.size(); ++i)
    {
        if (flags.at(i) == "--print")
        {
            print(text);
        }
        else if (flags.at(i) == "--remove")
        {
            remove(parameters.at(i), text);
        }
        else if (flags.at(i) == "--substitute")
        {
            replace(parameters.at(i), text);
        }
        else if (flags.at(i) == "--frequency")
        {

        }
        else if (flags.at(i) == "--table")
        {

        }
    }

     
    return 0;
}