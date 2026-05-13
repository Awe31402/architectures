// This class violates the Single Responsibility Principle (SRP)
// because it has multiple responsibilities:
class FileManagerAndParser {
public:
    int read(std::string file_path) {
        return 0; // read file and return content
    }

    void write(std::string file_path, std::string content) {
        // write content to file
    }

    std::vector<int> parse(std::string content) {
        // parse content
        return std::vector<int>(); // Placeholder return
    }
};

// Refactored version adhering to SRP:
class FileManager {
public:
    int read(std::string file_path) {
        return 0; // read file and return content
    }

    void write(std::string file_path, std::string content) {
        // write content to file
    }
};

class Parser {
public:
    std::vector<int> parse(std::string content) {
        // parse content
        return std::vector<int>(); // Placeholder return
    }
};