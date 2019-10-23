#pragma once

#include <Shaders/ShaderCompiler.hpp>
#include <Resources/FrameResources.hpp>
#include <Resources/ResourceHelper.hpp>
#include <Pipelines/PipelineInfo.hpp>
#include <DemoApp.hpp>

#include <Extensions/ImGui/ImGuiWindows.hpp>

#define __DIRECTX12__MODE__
#define __VULKAN__MODE__

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

struct TriangleDemoUIComponent {
	glm::vec3 TrianglePositions[3];
	glm::vec4 Color;

	TriangleDemoUIComponent();

	auto programStateView() const -> std::shared_ptr<CodeRed::ImGuiView> { return mProgramStateView; }
	
	auto triangleView() const -> std::shared_ptr<CodeRed::ImGuiView> { return mTriangleView; }
private:
	std::shared_ptr<CodeRed::ImGuiView> mProgramStateView;
	std::shared_ptr<CodeRed::ImGuiView> mTriangleView;
};

class TriangleDemoApp final : public Demo::DemoApp {
public:
	TriangleDemoApp(
		const std::string& name,
		const size_t width,
		const size_t height);

	~TriangleDemoApp();
private:
	void update(float delta) override;
	void render(float delta) override;

	void initialize();
	
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

	size_t mCurrentFrameIndex = 0;

	std::shared_ptr<TriangleDemoUIComponent> mUIComponent;
	
	std::shared_ptr<CodeRed::GpuLogicalDevice> mDevice;
	std::shared_ptr<CodeRed::GpuSwapChain> mSwapChain;

	std::shared_ptr<CodeRed::GpuCommandAllocator> mCommandAllocator;
	std::shared_ptr<CodeRed::GpuGraphicsCommandList> mCommandList;
	std::shared_ptr<CodeRed::GpuCommandQueue> mCommandQueue;

	std::vector<CodeRed::FrameResources> mFrameResources =
		std::vector<CodeRed::FrameResources>(maxFrameResources);

	std::shared_ptr<CodeRed::GpuBuffer> mViewBuffer;

	std::shared_ptr<CodeRed::GpuPipelineFactory> mPipelineFactory;
	std::shared_ptr<CodeRed::PipelineInfo> mPipelineInfo;

	std::shared_ptr<CodeRed::ImGuiWindows> mImGuiWindows;
	
	std::vector<CodeRed::Byte> mVertexShaderCode;
	std::vector<CodeRed::Byte> mPixelShaderCode;
};