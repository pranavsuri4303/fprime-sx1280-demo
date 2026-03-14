// ======================================================================
// \title  RadioDemoTopologyDefs.hpp
// \brief required header file containing the required definitions for the topology autocoder
//
// ======================================================================
#ifndef RADIODEMO_RADIODEMOTOPOLOGYDEFS_HPP
#define RADIODEMO_RADIODEMOTOPOLOGYDEFS_HPP

#include "Svc/Subtopologies/CdhCore/PingEntries.hpp"
#include "Svc/Subtopologies/ComCcsds/PingEntries.hpp"
#include "Svc/Subtopologies/DataProducts/PingEntries.hpp"
#include "Svc/Subtopologies/FileHandling/PingEntries.hpp"

#include "Svc/Subtopologies/CdhCore/SubtopologyTopologyDefs.hpp"
#include "Svc/Subtopologies/ComCcsds/SubtopologyTopologyDefs.hpp"
#include "Svc/Subtopologies/DataProducts/SubtopologyTopologyDefs.hpp"
#include "Svc/Subtopologies/FileHandling/SubtopologyTopologyDefs.hpp"

#include "Svc/Subtopologies/ComCcsds/Ports_ComPacketQueueEnumAc.hpp"
#include "Svc/Subtopologies/ComCcsds/Ports_ComBufferQueueEnumAc.hpp"

#include "RadioDemo/Top/FppConstantsAc.hpp"

namespace PingEntries {
    namespace Sx1280Demo_rateGroup1 { enum { WARN = 3, FATAL = 5 }; }
    namespace Sx1280Demo_rateGroup2 { enum { WARN = 3, FATAL = 5 }; }
    namespace Sx1280Demo_rateGroup3 { enum { WARN = 3, FATAL = 5 }; }
    namespace Sx1280Demo_cmdSeq     { enum { WARN = 3, FATAL = 5 }; }
}  // namespace PingEntries

namespace Sx1280Demo {

struct TopologyState {
    CdhCore::SubtopologyState cdhCore;
    ComCcsds::SubtopologyState comCcsds;
    DataProducts::SubtopologyState dataProducts;
    FileHandling::SubtopologyState fileHandling;
};

namespace PingEntries = ::PingEntries;

}  // namespace Sx1280Demo

#endif
