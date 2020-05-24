#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Bioba
{
	class BIO_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_EditorLogger;
	public:
		static void InitLog();
		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetEditorLogger() { return s_EditorLogger; }


	};

}

#define BIO_ENGINE_TRACE(...)	Bioba::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define BIO_ENGINE_INFO(...)	Bioba::Log::GetEngineLogger()->info(__VA_ARGS__)
#define BIO_ENGINE_WARN(...)	Bioba::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define BIO_ENGINE_ERROR(...)	Bioba::Log::GetEngineLogger()->error(__VA_ARGS__)

#define BIO_EDITOR_TRACE(...)	Bioba::Log::GetEditorLogger()->trace(__VA_ARGS__)
#define BIO_EDITOR_INFO(...)	Bioba::Log::GetEditorLogger()->info(__VA_ARGS__)
#define BIO_EDITOR_WARN(...)	Bioba::Log::GetEditorLogger()->warn(__VA_ARGS__)
#define BIO_EDITOR_ERROR(...)	Bioba::Log::GetEditorLogger()->error(__VA_ARGS__)

