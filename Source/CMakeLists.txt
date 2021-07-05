##-----------------------------------------------------------------
##
##
##
##
##
##
##
##
##-----------------------------------------------------------------


##-------------------------------------------------------------------------
set(SYSTEM_SOURCES_files_SourceFiles
	SourceFile/System/FileSystem.cpp
	SourceFile/System/TimeSystem.cpp	
)

source_group("Source\\System" FILES ${SYSTEM_SOURCES_files_SourceFiles})

set(System_source_files ${SYSTEM_SOURCES_files_SourceFiles})



set(SYSTEM_SOURCES_files_HeadFiles
	Include/System/FileSystem.h
	Include/System/TimeSystem.h
	Include/System/SystemMacros.h
	Include/System/SystemTypeDefines.h
)

source_group("Include\\System" FILES ${SYSTEM_SOURCES_files_HeadFiles})

set(System_head_files ${SYSTEM_SOURCES_files_HeadFiles})
##-------------------------------------------------------------------------

set(WINDOWS_SOURCES_files_SourceFiles
	SourceFile/Windows/WindowsFileSystem.cpp
	SourceFile/Windows/WindowsTimeSystem.cpp
)

source_group("Source\\Windows" FILES ${WINDOWS_SOURCES_files_SourceFiles})

set(Windows_source_files ${WINDOWS_SOURCES_files_SourceFiles})



set(WINDOWS_SOURCES_files_HeadFiles
	Include/Windows/WindowsFileSystem.h
	Include/Windows/WindowsTimeSystem.h
)

source_group("Include\\Windows" FILES ${WINDOWS_SOURCES_files_HeadFiles})

set(Windows_head_files ${WINDOWS_SOURCES_files_HeadFiles})

##--------------------------------------------------------------------------

set(LINUX_SOURCES_files_SourceFiles
	SourceFile/Linux/LinuxFileSystem.cpp
	SourceFile/Linux/LinuxTimeSystem.cpp
)

source_group("Source\\Linux" FILES ${LINUX_SOURCES_files_SourceFiles})

set(Linux_source_files ${LINUX_SOURCES_files_SourceFiles})


set(LINUX_SOURCES_files_HeadFiles
	Include/Linux/LinuxFileSystem.h
	Include/Linux/LinuxTimeSystem.h
)

source_group("Include\\Linux" FILES ${LINUX_SOURCES_files_HeadFiles})

set(Linux_head_files ${LINUX_SOURCES_files_HeadFiles})
##--------------------------------------------------------------------------

if(WIN32)
add_definitions(-D_WIN_)
set(SOURCES_ 
	${System_head_files} 
	${Windows_head_files}
	${System_source_files} 
	${Windows_source_files}
)


else(WIN32)

set(SOURCES_ 
	${System_source_files}
	${Linux_source_files}
	${System_head_files}
	${Linux_head_files}
)
#ADD_DEPENDENCIES(${ProjectName} "dl")
#TARGET_LINK_LIBRARIES(${ProjectName} dl)
endif(WIN32)


SET(ProjectName SystemLib)

ADD_LIBRARY(${ProjectName} STATIC ${SOURCES_})
SET_TARGET_PROPERTIES(${ProjectName} PROPERTIES FOLDER "SystemLib")

