// ======================================================================
// \title  Main.cpp
// \brief main program for the F' application
//
// ======================================================================

#include <RadioDemo/Top/RadioDemoTopology.hpp>
#include <Os/Os.hpp>
#include <signal.h>
#include <cstdio>
#include <cstring>

static void print_usage(const char* app) {
    (void)printf("Usage: ./%s [-h|--help]\n", app);
}

static void signalHandler(int signum) {
    (void)signum;
    Sx1280Demo::stopRateGroups();
}

int main(int argc, char* argv[]) {
    Os::init();

    if (argc > 1) {
        if ((std::strcmp(argv[1], "-h") == 0) || (std::strcmp(argv[1], "--help") == 0)) {
            print_usage(argv[0]);
            return 0;
        }

        print_usage(argv[0]);
        return 1;
    }

    Sx1280Demo::TopologyState inputs{};

    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    (void)printf("Hit Ctrl-C to quit\n");

    Sx1280Demo::setupTopology(inputs);
    Sx1280Demo::startRateGroups(Fw::TimeInterval(1, 0));
    Sx1280Demo::teardownTopology(inputs);

    (void)printf("Exiting...\n");
    return 0;
}
