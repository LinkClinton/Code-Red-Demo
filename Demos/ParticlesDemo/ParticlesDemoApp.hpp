#pragma once
#include "ParticleTextureGenerator.hpp"

#include <Resources/ResourceHelper.hpp>
#include <DemoApp.hpp>

#include <Extensions/ImGui/ImGuiWindows.hpp>

struct Particle {
	glm::vec2 Position = glm::vec2(0);
	glm::vec2 Forward = glm::vec2(0);
	glm::vec2 Size = glm::vec2(1);

	Particle() = default;

	Particle(
		const glm::vec2 &position,
		const glm::vec2 &forward,
		const glm::vec2 &size) :
		Position(position), Forward(forward), Size(size) {}

	void reverseIfOut(
		glm::vec2& offset,
		const size_t width,
		const size_t height);
};

struct ParticlesDemoUIComponent {
	std::optional<std::vector<Particle>*> Particles;
	
	bool Pause = false;

	ParticlesDemoUIComponent();

	auto programStateView() const -> std::shared_ptr<CodeRed::ImGuiView> { return mProgramStateView; }

	auto particlesView() const -> std::shared_ptr<CodeRed::ImGuiView> { return mParticlesView; }
private:
	std::shared_ptr<CodeRed::ImGuiView> mProgramStateView;
	std::shared_ptr<CodeRed::ImGuiView> mParticlesView;
};

class ParticlesDemoApp final : public Demo::DemoApp {
public:
	ParticlesDemoApp(
		const std::string& name,
		const size_t width,
		const size_t height);

	~ParticlesDemoApp();
private:
	void update(float delta) override;
	void render(float delta) override;
	void initialize();
	
	void initializeParticles();
	
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
	const size_t maxParticleSize = 20;
	const size_t particleCount = 2000;
	
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

	std::shared_ptr<CodeRed::GpuSampler> mSampler;

	std::shared_ptr<CodeRed::GpuPipelineFactory> mPipelineFactory;
	std::shared_ptr<CodeRed::PipelineInfo> mPipelineInfo;

	std::shared_ptr<CodeRed::ImGuiWindows> mImGuiWindows;
	std::shared_ptr<ParticlesDemoUIComponent> mUIComponent;
	
	std::shared_ptr<ParticleTextureGenerator> mParticleTextureGenerator;
	
	std::vector<CodeRed::Byte> mVertexShaderCode;
	std::vector<CodeRed::Byte> mPixelShaderCode;

	std::vector<Particle> mParticles = std::vector<Particle>(particleCount);
	std::vector<glm::mat4x4> mTransform = std::vector<glm::mat4x4>(particleCount);
};
