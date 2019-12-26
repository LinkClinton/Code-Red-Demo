#pragma once

#include <Shaders/ShaderCompiler.hpp>
#include <Resources/FrameResources.hpp>
#include <Resources/ResourceHelper.hpp>
#include <Pipelines/PipelineInfo.hpp>
#include <DemoApp.hpp>

#include <Extensions/ImGui/ImGuiWindows.hpp>

#include "FlowersGenerator.hpp"

//#define __DIRECTX12__MODE__
#define __VULKAN__MODE__

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

struct FlowersDemoUIComponent {
	size_t MaxFlowers = 0;
	size_t NowFlowers = 0;
	
	bool Pause = false;

	FlowersDemoUIComponent();
		
	auto programStateView() const -> std::shared_ptr<CodeRed::ImGuiView> { return mProgramStateView; }

	auto flowersView() const -> std::shared_ptr<CodeRed::ImGuiView> { return mFlowersView; }
private:
	std::shared_ptr<CodeRed::ImGuiView> mProgramStateView;
	std::shared_ptr<CodeRed::ImGuiView> mFlowersView;
};

class FlowersDemoApp final : public Demo::DemoApp {
public:
	FlowersDemoApp(
		const std::string& name,
		const size_t width,
		const size_t height);

	~FlowersDemoApp();
private:
	void update(float delta) override;
	void render(float delta) override;

	void initialize();

	void initializeFlowers();

	void initializeCommands();

	void initializeSwapChain();

	void initializeBuffers();

	void initializeShaders();

	void initializeSamplers();

	void initializeTextures();

	void initializePipeline();

	void initializeImGuiWindows();

	void initializeDescriptorHeaps();
private:
	const size_t maxFrameResources = 2;
	const size_t flowersCount = 500;

	size_t mCurrentFrameIndex = 0;

	std::shared_ptr<CodeRed::GpuLogicalDevice> mDevice;
	std::shared_ptr<CodeRed::GpuSwapChain> mSwapChain;

	std::shared_ptr<CodeRed::GpuCommandAllocator> mCommandAllocator;
	std::shared_ptr<CodeRed::GpuGraphicsCommandList> mCommandList;
	std::shared_ptr<CodeRed::GpuCommandQueue> mCommandQueue;

	std::vector<CodeRed::FrameResources> mFrameResources =
		std::vector<CodeRed::FrameResources>(maxFrameResources);

	std::shared_ptr<CodeRed::GpuBuffer> mVertexBuffer;
	std::shared_ptr<CodeRed::GpuBuffer> mIndexBuffer;
	std::shared_ptr<CodeRed::GpuBuffer> mViewBuffer;

	std::shared_ptr<CodeRed::GpuPipelineFactory> mPipelineFactory;
	std::shared_ptr<CodeRed::PipelineInfo> mPipelineInfo;

	std::shared_ptr<CodeRed::ImGuiWindows> mImGuiWindows;
	std::shared_ptr<FlowersDemoUIComponent> mUIComponent;

	std::shared_ptr<FlowersGenerator> mFlowersGenerator;

	std::vector<CodeRed::Byte> mVertexShaderCode;
	std::vector<CodeRed::Byte> mPixelShaderCode;
};