#pragma once

void CommandHelp(wstringstream& Params_, CUser& User_);
void CommandSetUserLevel(wstringstream& Params_, CUser& User_);
void CommandAddResources(wstringstream& Params_, CUser& User_);
void CommandSetResources(wstringstream& Params_, CUser& User_);
void CommandSetMapIndex(wstringstream& Params_, CUser& User_);
void CommandSetPoint(wstringstream& Params_, CUser& User_);
void CommandSetChar(wstringstream& Params_, CUser& User_);
void CommandUnsetChar(wstringstream& Params_, CUser& User_);
void CommandQuestComplete(wstringstream& Params_, CUser& User_);
void CommandQuestSet(wstringstream& Params_, CUser& User_);
