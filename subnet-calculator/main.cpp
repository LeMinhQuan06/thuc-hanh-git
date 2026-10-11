#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

bool readNumber(const string& text,
                unsigned limit, unsigned& value) {
    if (text.empty() || text.size() > 3) {
        return false;
    }

    value = 0;

    for (char c : text) {
        if (c < '0' || c > '9') {
            return false;
        }

        value = value * 10 + static_cast<unsigned>(c - '0');

        if (value > limit) {
            return false;
        }
    }

    return true;
}

bool parseCIDR(const string& text,
               uint32_t& ip, unsigned& prefix) {
    const auto slash = text.find('/');

    if (slash == string::npos ||
        text.find('/', slash + 1) != string::npos) {
        return false;
    }

    if (!readNumber(text.substr(slash + 1), 32, prefix)) {
        return false;
    }

    const string address = text.substr(0, slash);
    size_t start = 0;
    ip = 0;

    for (unsigned i = 0; i < 4; ++i) {
        const auto dot = address.find('.', start);

        if ((i < 3 && dot == string::npos) ||
            (i == 3 && dot != string::npos)) {
            return false;
        }

        const string part = address.substr(
            start,
            dot == string::npos
                ? string::npos : dot - start
        );

        unsigned octet = 0;

        if (!readNumber(part, 255, octet)) {
            return false;
        }

        ip = (ip << 8) | static_cast<uint32_t>(octet);

        if (i < 3) {
            start = dot + 1;
        }
    }

    return true;
}

string toIPv4(uint32_t value) {
    return to_string((value >> 24) & 255u) + "." +
           to_string((value >> 16) & 255u) + "." +
           to_string((value >> 8) & 255u) + "." +
           to_string(value & 255u);
}

int main(int argc, char* argv[]) {
    string input;

    if (argc == 2) {
        input = argv[1];
    } else if (argc == 1) {
        cout << "Nhap IPv4/CIDR, vi du 192.168.1.130/26: ";

        if (!getline(cin, input)) {
            return 2;
        }
    } else {
        cerr << "Cach dung: subnet.exe IPv4/prefix\n";
        return 2;
    }

    uint32_t ip = 0;
    unsigned prefix = 0;

    if (!parseCIDR(input, ip, prefix)) {
        cerr
            << "Du lieu khong hop le.\n"
            << "Can 4 octet tu 0 den 255, prefix tu 0 den 32.\n"
            << "Vi du: 192.168.1.130/26\n";

        return 2;
    }

    const uint32_t mask =
        prefix == 0 ? 0u : (0xFFFFFFFFu << (32u - prefix));

    const uint32_t network = ip & mask;
    const uint32_t last = network | ~mask;

    const uint64_t total =
        uint64_t{1} << (32u - prefix);

    const bool ordinarySubnet = prefix <= 30;

    const uint32_t firstHost =
        ordinarySubnet ? network + 1 : network;

    const uint32_t lastHost =
        ordinarySubnet ? last - 1 : last;

    const uint64_t hosts =
        ordinarySubnet ? total - 2 : total;

    cout
        << "\n=== IPV4 SUBNET CALCULATOR ===\n"
        << "IP           : " << toIPv4(ip) << "\n"
        << "Prefix       : /" << prefix << "\n"
        << "Subnet mask  : " << toIPv4(mask) << "\n"
        << "Network      : " << toIPv4(network) << "\n"
        << "Broadcast    : "
        << (ordinarySubnet ? toIPv4(last) : "Khong ap dung")
        << "\n"
        << "Host dau     : " << toIPv4(firstHost) << "\n"
        << "Host cuoi    : " << toIPv4(lastHost) << "\n"
        << "Tong dia chi : " << total << "\n"
        << "So host      : " << hosts << "\n";

    if (prefix == 31) {
        cout
            << "Ghi chu: /31 dung cho lien ket point-to-point.\n";
    } else if (prefix == 32) {
        cout
            << "Ghi chu: /32 bieu dien mot dia chi don.\n";
    } else {
        cout
            << "So host tinh theo cong thuc subnet; "
            << "chua loai cac dai dia chi danh rieng.\n";
    }

    return 0;
}