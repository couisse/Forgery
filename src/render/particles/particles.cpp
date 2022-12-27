#include "particles.hpp"

/// Particle Generator

void ParticleGenerator::createParticleQuad(sf::VertexArray& target, sf::Vector2f pos){
    target.append(sf::Vertex(pos, sf::Color::Red));
    target.append(sf::Vertex(sf::Vector2f(pos.x+PARTICLE_SIZE.x, pos.y), sf::Color::Red));
    target.append(sf::Vertex(sf::Vector2f(pos.x+PARTICLE_SIZE.x, pos.y+PARTICLE_SIZE.y), sf::Color::Red));
    target.append(sf::Vertex(sf::Vector2f(pos.x, pos.y+PARTICLE_SIZE.y), sf::Color::Red));
}

///Particle system

ParticlesSystem::ParticlesSystem(ParticleUpdater* updater, sf::Vector2u range, sf::VertexArray* holder): m_updater(updater->copy()), //copying the updater
                                                                                                    m_range(range), m_refHolder(holder){}

ParticlesSystem::~ParticlesSystem(){
    delete m_updater;
}

void ParticlesSystem::update(){
    for (unsigned int i = m_range.x; i<m_range.y; i++){
        m_updater->update((*m_refHolder)[i]);
    }
}

///Particles

Particles::Particles(){
    m_array.setPrimitiveType(sf::Quads);
}

Particles::~Particles(){
}

void Particles::update(){
    size_t n = m_systems.size(); //the size of the array is not modified on update
    for (unsigned int i=0; i<n; i++){
        m_systems[i].update();
    }
}

void Particles::addParticles(ParticleGenerator* generator, ParticleUpdater* updater){
    size_t start = m_array.getVertexCount();
    m_systems.emplace_back(updater, sf::Vector2u(start, start+generator->generate(m_array)), &m_array);
}

void Particles::render(sf::RenderWindow* target){
    target->draw(m_array);
}
