<?php
/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2013  FusionDirectory

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

class ipmiClient extends simplePlugin
{
  var $objectclasses  = array('ipmiClient');
  var $displayHeader  = TRUE;

  //~ var $inheritance = array("gosaGroupOfNames" => "member");

  static function plInfo ()
  {
    return array(
      'plShortName'     => _('IPMI client'),
      'plDescription'   => _('Edit IPMI client settings'),
      'plSelfModify'    => FALSE,
      'plCategory'      => array('workstation','server'),
      'plObjectType'    => array('workstation','server'),

      'plProvidedAcls'  => parent::generatePlProvidedAcls(self::getAttributesInfo())
    );
  }

  static function getAttributesInfo ()
  {
    return array(
      'main' => array(
        'name'  => _('IPMI client settings'),
        'attrs' => array(
          new StringAttribute (
            _('IP'), _('IP of the IPMI interface'),
            'fdIpmiIP', TRUE
          ),
          new StringAttribute (
            _('User login'), _('IPMI user login'),
            'fdIpmiLogin', TRUE,
            ''
          ),
          new PasswordAttribute (
            _('User password'), _('IPMI user password'),
            'fdIpmiPassword', TRUE
          ),
        )
      ),
    );
  }

  function __construct(&$config, $dn = NULL, $object = NULL)
  {
    parent::__construct($config, $dn, $object);
  }
}

?>