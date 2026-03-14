// ======================================================================
// \title  RadioDemoTopology.cpp
// \brief cpp file containing the topology instantiation code
//
// ======================================================================

#include <RadioDemo/Top/RadioDemoTopologyAc.hpp>
#include <Fw/Types/MallocAllocator.hpp>

namespace Sx1280Demo {

Fw::MallocAllocator mallocator;

Svc::RateGroupDriver::DividerSet rateGroupDivisorsSet{{{1, 0}, {2, 0}, {4, 0}}};

U32 rateGroup1Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};
U32 rateGroup2Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};
U32 rateGroup3Context[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};

void configureTopology() {
    rateGroupDriver.configure(rateGroupDivisorsSet);

    rateGroup1.configure(rateGroup1Context, FW_NUM_ARRAY_ELEMENTS(rateGroup1Context));
    rateGroup2.configure(rateGroup2Context, FW_NUM_ARRAY_ELEMENTS(rateGroup2Context));
    rateGroup3.configure(rateGroup3Context, FW_NUM_ARRAY_ELEMENTS(rateGroup3Context));

    cmdSeq.allocateBuffer(0, mallocator, 5 * 1024);
}

void setupTopology(const TopologyState& state) {
    initComponents(state);
    setBaseIds();
    connectComponents();
    regCommands();
    configComponents(state);
    configureTopology();
    loadParameters();
    startTasks(state);
}

void startRateGroups(const Fw::TimeInterval& interval) {
    timer.startTimer(interval);
}

void stopRateGroups() {
    timer.quit();
}

void teardownTopology(const TopologyState& state) {
    stopTasks(state);
    freeThreads(state);

    cmdSeq.deallocateBuffer(mallocator);

    tearDownComponents(state);
}

}  // namespace Sx1280Demo
