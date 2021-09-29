#include "stdafx.h"
#include "skill.h"

HRESULT skill::init(int itemMAX, float range)
{
	_skillMAX = itemMAX;
	_range = range;

	return S_OK;
}

void skill::release()
{
}

void skill::update()
{
	move();
}

void skill::render()
{
	for (_viSkill = _vskill.begin(); _viSkill != _vskill.end(); ++_viSkill)
	{
		_viSkill->SkillImage->frameRender(getMemDC(),
			_viSkill->rc.left,
			_viSkill->rc.top,
			_viSkill->SkillImage->getFrameX(), 0);

		_viSkill->count++;

		if (_viSkill->count % 5 == 0)
		{
			_viSkill->SkillImage->setFrameX(_viSkill->SkillImage->getFrameX() + 1);

			//최대 프레임보다 커지면
			if (_viSkill->SkillImage->getFrameX() >= _viSkill->SkillImage->getMaxFrameX())
			{
				_viSkill->SkillImage->setFrameX(0);
			}

			_viSkill->count = 0;
		}
	}

}

void skill::setSkill(float x, float y)
{
	if (_skillMAX < _vskill.size()) return;

	tagSkill Skill;
	ZeroMemory(&Skill, sizeof(tagSkill));

	Skill.SkillImage = new image;
	Skill.SkillImage->init("magic/해골스컬.bmp", 0, 0, 1280, 132, 8, 1, true, RGB(255, 0, 255));
	Skill.speed = 20.0f;
	Skill.x = Skill.fireX = x;
	Skill.y = Skill.fireY = y;
	Skill.rc = RectMakeCenter(Skill.x, Skill.y,
		Skill.SkillImage->getFrameWidth(),
		Skill.SkillImage->getFrameHeight());

	_vskill.push_back(Skill);
}

void skill::move()
{
	for (_viSkill = _vskill.begin(); _viSkill != _vskill.end();)
	{
		_viSkill->x += _viSkill->speed;
		_viSkill->rc = RectMakeCenter(_viSkill->x, _viSkill->y,
			_viSkill->SkillImage->getFrameWidth(),
			_viSkill->SkillImage->getFrameHeight());

		//사거리보다 더 멀리 나가면(?)
		if (_range < getDistance(_viSkill->x, _viSkill->y, _viSkill->fireX, _viSkill->fireY))
		{
			EFFECTMANAGER->play("스킬폭발", _viSkill->x, _viSkill->y);
			SAFE_RELEASE(_viSkill->SkillImage);
			SAFE_DELETE(_viSkill->SkillImage);
			_viSkill = _vskill.erase(_viSkill);

			
			
		}
		else ++_viSkill;

	}
}

void skill::removeSkill(int arrNum)
{
	_vskill[arrNum].SkillImage->release();
	_vskill.erase(_vskill.begin() + arrNum);

}
