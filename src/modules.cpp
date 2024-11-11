#include "modules.hpp"

void rf::Modules::cpu(void)
{
    FILE* fp = popen("grep 'model name' /proc/cpuinfo | head -n 1", "r");
    if (!fp) {
        std::cerr << "Error opening stream!" << std::endl;
        return;
    }

    char buffer[128];
    std::string cpu;
    while (fgets(buffer, sizeof(buffer), fp)) {
        cpu += buffer;
    }

    fclose(fp);

    size_t pos = cpu.find(':');
    if (pos != std::string::npos) {
        cpu = cpu.substr(pos + 2);
    }

    std::cout << std::format("CPU: {}", cpu);
}