#include "level.h"
#include <sgg/graphics.h>
#include "player.h"
#include "util.h"

Level::Level(const std::string& name)
	: GameObject(name)
{
	m_brush_background.outline_opacity = 0.0f;
	m_brush_background.texture = m_state->getFullAssetPath("background6.png");


}

void Level::draw()
{
	float w = m_state->getCanvasWidth();
	float h = m_state->getCanvasHeight();

	float offset_x = m_state->m_global_offset_x + w / 2.0f;
	float offset_y = m_state->m_global_offset_y  + h / 2.0f;

	//draw background
	graphics::drawRect(1.55f * offset_x, 0.4f * offset_y, 1.5f * w,1.5f * h, m_brush_background);

}

Level::~Level()
{
	for (auto p_go : m_static_objects)
		delete p_go;
	for (auto p_go : m_dynamic_objects)
		delete p_go;
}