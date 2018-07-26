<?php
/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2017-2018 FusionDirectory

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/

class publicFormsConfig extends simplePlugin
{
  static function plInfo()
  {
    return array(
      'plShortName'   => _('Public forms configuration'),
      'plDescription' => _('FusionDirectory public forms plugin configuration'),
      'plObjectClass' => array('fdPublicFormsPluginConf'),
      'plCategory'    => array('configuration'),
      'plObjectType'  => array('smallConfig'),

      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    );
  }

  static function getAttributesInfo ()
  {
    return array(
      'main' => array(
        'name'  => _('Public forms'),
        'attrs' => array(
          new StringAttribute (
            _('Public forms RDN'), _('Branch in which public forms will be stored'),
            'fdPublicFormRDN', TRUE,
            'ou=forms'
          ),
        )
      ),
    );
  }
}
?>