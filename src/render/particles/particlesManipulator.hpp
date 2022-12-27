#ifndef PARTICLESMANIPULATOR_HPP_INCLUDED
#define PARTICLESMANIPULATOR_HPP_INCLUDED

#include "particles.hpp"
#include "../../utils/vector.hpp"

/** \brief This header provides standards Particles generators and updators
 */

///Generators

/** \brief Generates a line of particles from point start to point end
 *      particles are separated from a distance of spacing along the segment
 */

class ParticleLine: public ParticleGenerator{

protected:
    const sf::Vector2f m_start, m_end;
    const float m_spacing;

public:
    ParticleLine(sf::Vector2f start, sf::Vector2f end, float spacing = PARTICLE_SIZE.x);
    virtual size_t generate(sf::VertexArray& target);
};

///Updaters

/** \brief offset the vertices with a constant vector on each frame
 */
class VertexOffset: public ParticleUpdater {

protected:
    sf::Vector2f m_offset;

public:
    VertexOffset(sf::Vector2f offset);
    virtual ~VertexOffset(){}
    virtual void update(sf::Vertex& vertex);
    virtual ParticleUpdater* copy() {return new VertexOffset(*this);}
};


#endif // PARTICLESMANIPULATOR_HPP_INCLUDED
