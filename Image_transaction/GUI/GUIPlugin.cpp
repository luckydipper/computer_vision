#include "GUI.h"
#include "GUIPlugin.h"
#include <QtCore/QtPlugin>

GUIPlugin::GUIPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void GUIPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool GUIPlugin::isInitialized() const
{
    return initialized;
}

QWidget *GUIPlugin::createWidget(QWidget *parent)
{
    return new GUI(parent);
}

QString GUIPlugin::name() const
{
    return "GUI";
}

QString GUIPlugin::group() const
{
    return "My Plugins";
}

QIcon GUIPlugin::icon() const
{
    return QIcon();
}

QString GUIPlugin::toolTip() const
{
    return QString();
}

QString GUIPlugin::whatsThis() const
{
    return QString();
}

bool GUIPlugin::isContainer() const
{
    return false;
}

QString GUIPlugin::domXml() const
{
    return "<widget class=\"GUI\" name=\"GUI\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString GUIPlugin::includeFile() const
{
    return "GUI.h";
}
