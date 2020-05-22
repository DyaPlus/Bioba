#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Bioba::Log::s_EngineLogger;
std::shared_ptr<spdlog::logger> Bioba::Log::s_EditorLogger;

void Bioba::Log::InitLog()
{
	spdlog::set_pattern("%^[%I:%M] %n[%l] : %v%$ ");
	s_EngineLogger = spdlog::stdout_color_mt("ENGINE");
	s_EngineLogger->set_level(spdlog::level::trace);
	s_EditorLogger = spdlog::stdout_color_mt("EDITOR");
	s_EditorLogger->set_level(spdlog::level::trace);

}
