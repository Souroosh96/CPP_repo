#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janeiro", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    const int width_name = 20;
    const int width_population = 15;
    const int width_cost = 10;

    std::cout << std::setw(50) << std::right << tours.title << std::endl;
    std::cout << std::endl;

    // Header
    std::cout << std::setw(width_name) << std::left << "City" 
              << std::setw(width_population) << std::right << "Population" 
              << std::setw(width_cost) << std::right << "Cost" 
              << std::endl;
    std::cout << std::setw(width_name) << std::left << "-------------------" 
              << std::setw(width_population) << std::right << "-------------" 
              << std::setw(width_cost) << std::right << "----------" 
              << std::endl;

    for(auto& country : tours.countries) {   // loop through the countries
        std::cout << country.name << std::endl;
        for(auto& city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(width_name) << std::left << city.name 
                      << std::setw(width_population) << std::right << city.population 
                      << std::setw(width_cost) << std::right << std::fixed << std::setprecision(2) << city.cost 
                      << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
